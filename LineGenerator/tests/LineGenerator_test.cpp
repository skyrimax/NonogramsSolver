#include <gtest/gtest.h>

#include <AllPossibleLinesGenerator.hpp>
#include <LineGeneratorFilter.hpp>
#include <FSTLineSequencer.hpp>
#include <LineFilterBuilder.hpp>
#include <ILineFilter.hpp>

#include <vector>
#include <tuple>
#include <algorithm>

/**
 * @brief Test fixture
 * Contains list of line length and corresponding possible lines
 * 
 */
class AllPossibleLinesGeneratorTest: public ::testing::Test
{
protected:
    // test case type
    using testCaseType = std::pair<unsigned int,
                            std::vector<NS::ILineGenerator::Line>>;
    void SetUp() override
    {

        auto vectorlexicographicSorter = [](const auto& v1, const auto& v2){
            return std::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end());
        };

        // all possible lines from size 1 to 5
        testSequencesLines
            .push_back(
                testCaseType(
                    1,
                    {
                        {0},
                        {1}
                    }
                )
            );
        testSequencesLines
            .push_back(
                testCaseType(
                    2,
                    {
                        {0, 0},
                        {0, 1},
                        {1, 0},
                        {1, 1}
                    }
                )
            );
        testSequencesLines
            .push_back(
                testCaseType(
                    3,
                    {
                        {0, 0, 0},
                        {0, 0, 1},
                        {0, 1, 0},
                        {0, 1, 1},
                        {1, 0, 0},
                        {1, 0, 1},
                        {1, 1, 0},
                        {1, 1, 1}
                    }
                )
            );
        testSequencesLines
            .push_back(
                testCaseType(
                    4,
                    {
                        {0, 0, 0, 0},
                        {0, 0, 0, 1},
                        {0, 0, 1, 0},
                        {0, 0, 1, 1},
                        {0, 1, 0, 0},
                        {0, 1, 0, 1},
                        {0, 1, 1, 0},
                        {0, 1, 1, 1},
                        {1, 0, 0, 0},
                        {1, 0, 0, 1},
                        {1, 0, 1, 0},
                        {1, 0, 1, 1},
                        {1, 1, 0, 0},
                        {1, 1, 0, 1},
                        {1, 1, 1, 0},
                        {1, 1, 1, 1}
                    }
                )
            );
        testSequencesLines
            .push_back(
                testCaseType(
                    5,
                    {
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 1},
                        {0, 0, 0, 1, 0},
                        {0, 0, 0, 1, 1},
                        {0, 0, 1, 0, 0},
                        {0, 0, 1, 0, 1},
                        {0, 0, 1, 1, 0},
                        {0, 0, 1, 1, 1},
                        {0, 1, 0, 0, 0},
                        {0, 1, 0, 0, 1},
                        {0, 1, 0, 1, 0},
                        {0, 1, 0, 1, 1},
                        {0, 1, 1, 0, 0},
                        {0, 1, 1, 0, 1},
                        {0, 1, 1, 1, 0},
                        {0, 1, 1, 1, 1},
                        {1, 0, 0, 0, 0},
                        {1, 0, 0, 0, 1},
                        {1, 0, 0, 1, 0},
                        {1, 0, 0, 1, 1},
                        {1, 0, 1, 0, 0},
                        {1, 0, 1, 0, 1},
                        {1, 0, 1, 1, 0},
                        {1, 0, 1, 1, 1},
                        {1, 1, 0, 0, 0},
                        {1, 1, 0, 0, 1},
                        {1, 1, 0, 1, 0},
                        {1, 1, 0, 1, 1},
                        {1, 1, 1, 0, 0},
                        {1, 1, 1, 0, 1},
                        {1, 1, 1, 1, 0},
                        {1, 1, 1, 1, 1}
                    }
                )
            );

        for(auto& testSequenceLine : testSequencesLines){
            std::sort(testSequenceLine.second.begin(),
                        testSequenceLine.second.end(),
                        vectorlexicographicSorter);
        }
    }

    std::vector<testCaseType> testSequencesLines;
};

TEST_F(AllPossibleLinesGeneratorTest, HandlesSize0)
{
    EXPECT_EQ(NS::AllPossibleLinesGenerator(0).generateLines(), std::vector<NS::AllPossibleLinesGenerator::Line>());
}

TEST_F(AllPossibleLinesGeneratorTest, generateSize1to5) {
    auto vectorlexicographicSorter = [](const auto& v1, const auto& v2){
            return std::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end());
        };

    for(const auto& testSequenceLine : testSequencesLines) {
        auto lines = NS::AllPossibleLinesGenerator(testSequenceLine.first).generateLines();

        std::sort(lines.begin(),
                    lines.end(),
                    vectorlexicographicSorter);

        EXPECT_EQ(lines, testSequenceLine.second);
    }
}

/**
 * @brief Test fixture
 * Contains list of line sizes, filters and filtered possibilities
 * 
 */
class LineGeneratorFilterTest: public ::testing::Test
{
protected:
    // test case type
    using testCaseType = std::tuple<unsigned int, std::shared_ptr<NS::Sequence>,
                            std::vector<NS::ILineGenerator::Line>>;

    void SetUp() override
    {
        FSTLineSequencer sequencer;
        LineFilterBuilder filterBuilder;

        auto vectorlexicographicSorter = [](const auto& v1, const auto& v2){
            return std::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end());
        };

        testCases
            .push_back(
                testCaseType(
                    5,
                    std::make_shared<NS::Sequence>(std::initializer_list<unsigned int>({1, 1})),
                    {
                        {0, 0, 1, 0, 1},
                        {0, 1, 0, 0, 1},
                        {0, 1, 0, 1, 0},
                        {1, 0, 0, 0, 1},
                        {1, 0, 0, 1, 0},
                        {1, 0, 1, 0, 0}
                    }
                )
            );
        testCases
            .push_back(
                testCaseType(
                    5,
                    std::make_shared<NS::Sequence>(std::initializer_list<unsigned int>({5})),
                    {
                        {1, 1, 1, 1, 1}
                    }
                )
            );
        testCases
            .push_back(
                testCaseType(
                    5,
                    std::make_shared<NS::Sequence>(std::initializer_list<unsigned int>({3})),
                    {
                        {1, 1, 1, 0, 0},
                        {0, 1, 1, 1, 0},
                        {0, 0, 1, 1, 1}
                    }
                )
            );
        testCases
            .push_back(
                testCaseType(
                    5,
                    std::make_shared<NS::Sequence>(std::initializer_list<unsigned int>({1})),
                    {
                        {1, 0, 0, 0, 0},
                        {0, 1, 0, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 0, 1, 0},
                        {0, 0, 0, 0, 1}
                    }
                )
            );
        testCases
            .push_back(
                testCaseType(
                    5,
                    std::make_shared<NS::Sequence>(std::initializer_list<unsigned int>({2})),
                    {
                        {1, 1, 0, 0, 0},
                        {0, 1, 1, 0, 0},
                        {0, 0, 1, 1, 0},
                        {0, 0, 0, 1, 1}
                    }
                )
            );
        testCases
            .push_back(
                testCaseType(
                    5,
                    std::make_shared<NS::Sequence>(std::initializer_list<unsigned int>({4})),
                    {
                        {1, 1, 1, 1, 0},
                        {0, 1, 1, 1, 1}
                    }
                )
            );

        for(auto& testCase : testCases) {
            std::sort(std::get<2>(testCase).begin(),
                        std::get<2>(testCase).end(),
                        vectorlexicographicSorter);
        }
    }

    std::vector<testCaseType> testCases;
    std::shared_ptr<FSTLineSequencer> sequencer = std::make_shared<FSTLineSequencer>();
    LineFilterBuilder filterBuilder;
};

TEST_F(LineGeneratorFilterTest, HandlesSize0)
{
    EXPECT_EQ(NS::LineGeneratorFilter(
        filterBuilder.reset().sequenceLineFilter(std::make_shared<NS::Sequence>(std::initializer_list<unsigned int>({1})), sequencer).lineFilterInverter().makeLineFilter(),
        std::make_unique<NS::AllPossibleLinesGenerator>(0)).generateLines(),
        std::vector<NS::AllPossibleLinesGenerator::Line>());
}

TEST_F(LineGeneratorFilterTest, HandlesEmptySequence)
{
    EXPECT_EQ(NS::LineGeneratorFilter(
        filterBuilder.reset().sequenceLineFilter(std::make_shared<NS::Sequence>(std::initializer_list<unsigned int>({0})), sequencer).lineFilterInverter().makeLineFilter(),
        std::make_unique<NS::AllPossibleLinesGenerator>(5)).generateLines(),
        std::vector<NS::AllPossibleLinesGenerator::Line>());
}

TEST_F(LineGeneratorFilterTest, FiltersLvl1_1)
{
    auto vectorlexicographicSorter = [](const auto& v1, const auto& v2){
            return std::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end());
        };

    for(const auto& testCase : testCases) {
        auto lines = NS::LineGeneratorFilter(
            filterBuilder.reset().sequenceLineFilter(std::get<1>(testCase), sequencer).lineFilterInverter().makeLineFilter(),
            std::make_unique<NS::AllPossibleLinesGenerator>(std::get<0>(testCase))
        ).generateLines();

        std::sort(lines.begin(),
                    lines.end(),
                    vectorlexicographicSorter);

        EXPECT_EQ(lines, std::get<2>(testCase));
    }
}