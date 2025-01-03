#include <gtest/gtest.h>

#include <SequenceLineFilter.hpp>
#include <FSTLineSequencer.hpp>
#include <LineEmptyFilter.hpp>
#include <LineFillFilter.hpp>
#include <LineMatchFilter.hpp>
#include <LineFilterInverter.hpp>
#include <LineFilterBuilder.hpp>

#include <LineGeneratorBuilder.hpp>

#include <memory>
#include <vector>
#include <utility>

/**
 * @brief Test fixture
 * Contains list of lines and corresponding sequences
 * 
 */
class SequenceLineFilterTest: public ::testing::Test
{
protected:
    void SetUp() override
    {
        // lvl # 1-1 (5x5)
        // Rows
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, std::shared_ptr<NS::Sequence>>(
                    {0, 1, 0, 1, 0},
                    std::make_shared<NS::Sequence>(std::initializer_list<unsigned int>({1, 1}))
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, std::shared_ptr<NS::Sequence>>(
                    {1, 1, 1, 1, 1},
                    std::make_shared<NS::Sequence>(std::initializer_list<unsigned int>({5}))
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, std::shared_ptr<NS::Sequence>>(
                    {1, 1, 1, 1, 1},
                    std::make_shared<NS::Sequence>(std::initializer_list<unsigned int>({5}))
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, std::shared_ptr<NS::Sequence>>(
                    {0, 1, 1, 1, 0},
                    std::make_shared<NS::Sequence>(std::initializer_list<unsigned int>({3}))
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, std::shared_ptr<NS::Sequence>>(
                    {0, 0, 1, 0, 0},
                    std::make_shared<NS::Sequence>(std::initializer_list<unsigned int>({1}))
                )
            );
        // Columns
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, std::shared_ptr<NS::Sequence>>(
                    {0, 1, 1, 0, 0},
                    std::make_shared<NS::Sequence>(std::initializer_list<unsigned int>({2}))
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, std::shared_ptr<NS::Sequence>>(
                    {1, 1, 1, 1, 0},
                    std::make_shared<NS::Sequence>(std::initializer_list<unsigned int>({4}))
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, std::shared_ptr<NS::Sequence>>(
                    {0, 1, 1, 1, 1},
                    std::make_shared<NS::Sequence>(std::initializer_list<unsigned int>({4}))
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, std::shared_ptr<NS::Sequence>>(
                    {1, 1, 1, 1, 0},
                    std::make_shared<NS::Sequence>(std::initializer_list<unsigned int>({4}))
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, std::shared_ptr<NS::Sequence>>(
                    {0, 1, 1, 0, 0},
                    std::make_shared<NS::Sequence>(std::initializer_list<unsigned int>({2}))
                )
            );

        // lvl # 1-2 (10x10)
        // Rows
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, std::shared_ptr<NS::Sequence>>(
                    {1, 1, 0, 0, 1, 0, 0, 1, 1, 1},
                    std::make_shared<NS::Sequence>(std::initializer_list<unsigned int>({2, 1, 3}))
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, std::shared_ptr<NS::Sequence>>(
                    {1, 0, 0, 0, 0, 0, 1, 0, 1, 1},
                    std::make_shared<NS::Sequence>(std::initializer_list<unsigned int>({1, 1, 2}))
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, std::shared_ptr <NS::Sequence>>(
                    {1, 0, 0, 0, 0, 0, 1, 0, 1, 1},
                    std::make_shared<NS::Sequence>(std::initializer_list<unsigned int>({1, 1, 2}))
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, std::shared_ptr<NS::Sequence>>(
                    {1, 0, 0, 0, 0, 0, 0, 0, 1, 1},
                    std::make_shared<NS::Sequence>(std::initializer_list<unsigned int>({1, 2}))
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, std::shared_ptr<NS::Sequence>>(
                    {1, 1, 0, 0, 0, 0, 0, 1, 1, 1},
                    std::make_shared<NS::Sequence>(std::initializer_list<unsigned int>({2, 3}))
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, std::shared_ptr<NS::Sequence>>(
                    {1, 1, 1, 0, 0, 0, 1, 1, 1, 1},
                    std::make_shared<NS::Sequence>(std::initializer_list<unsigned int>({3, 4}))
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, std::shared_ptr<NS::Sequence>>(
                    {1, 1, 1, 1, 0, 1, 1, 1, 0, 1},
                    std::make_shared<NS::Sequence>(std::initializer_list<unsigned int>({4, 3, 1}))
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, std::shared_ptr<NS::Sequence>>(
                    {1, 0, 1, 1, 1, 1, 1, 0, 1, 0},
                    std::make_shared<NS::Sequence>(std::initializer_list<unsigned int>({1, 5, 1}))
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, std::shared_ptr<NS::Sequence>>(
                    {0, 1, 0, 1, 1, 0, 1, 1, 0, 1},
                    std::make_shared<NS::Sequence>(std::initializer_list<unsigned int>({1, 2, 2, 1}))
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, std::shared_ptr<NS::Sequence>>(
                    {1, 0, 1, 1, 0, 1, 0, 1, 1, 1},
                    std::make_shared<NS::Sequence>(std::initializer_list<unsigned int>({1, 2, 1, 3}))
                )
            );
        // Columns
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, std::shared_ptr<NS::Sequence>>(
                    {1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
                    std::make_shared<NS::Sequence>(std::initializer_list<unsigned int>({8, 1}))
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, std::shared_ptr<NS::Sequence>>(
                    {1, 0, 0, 0, 1, 1, 1, 0, 1, 0},
                    std::make_shared<NS::Sequence>(std::initializer_list<unsigned int>({1, 3, 1}))
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, std::shared_ptr<NS::Sequence>>(
                    {0, 0, 0, 0, 0, 1, 1, 1, 0, 1},
                    std::make_shared<NS::Sequence>(std::initializer_list<unsigned int>({3, 1}))
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, std::shared_ptr<NS::Sequence>>(
                    {0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
                    std::make_shared<NS::Sequence>(std::initializer_list<unsigned int>({4}))
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, std::shared_ptr<NS::Sequence>>(
                    {1, 0, 0, 0, 0, 0, 0, 1, 1, 0},
                    std::make_shared<NS::Sequence>(std::initializer_list<unsigned int>({1, 2}))
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, std::shared_ptr<NS::Sequence>>(
                    {0, 0, 0, 0, 0, 0, 1, 1, 0, 1},
                    std::make_shared<NS::Sequence>(std::initializer_list<unsigned int>({2, 1}))
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, std::shared_ptr<NS::Sequence>>(
                    {0, 1, 1, 0, 0, 1, 1, 1, 1, 0},
                    std::make_shared<NS::Sequence>(std::initializer_list<unsigned int>({2, 4}))
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, std::shared_ptr<NS::Sequence>>(
                    {1, 0, 0, 0, 1, 1, 1, 0, 1, 1},
                    std::make_shared<NS::Sequence>(std::initializer_list<unsigned int>({1, 3, 2}))
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, std::shared_ptr<NS::Sequence>>(
                    {1, 1, 1, 1, 1, 1, 0, 1, 0, 1},
                    std::make_shared<NS::Sequence>(std::initializer_list<unsigned int>({6, 1, 1}))
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, std::shared_ptr<NS::Sequence>>(
                    {1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
                    std::make_shared<NS::Sequence>(std::initializer_list<unsigned int>({7, 2}))
                )
            );
    }

    std::vector<std::pair<ILineSequencer::Line, std::shared_ptr<NS::Sequence>>> testLinesSequences;
};

TEST_F(SequenceLineFilterTest, SequenceLineFilter) {
    std::shared_ptr<FSTLineSequencer> sequencer = std::make_shared<FSTLineSequencer>();

    for(const auto& lineSequence : testLinesSequences) {
        EXPECT_TRUE(SequenceLineFilter(lineSequence.second, sequencer)(lineSequence.first));
    }
}

TEST_F(SequenceLineFilterTest, LineFilterInverter) {
    std::shared_ptr<FSTLineSequencer> sequencer = std::make_shared<FSTLineSequencer>();

    for(const auto& lineSequence : testLinesSequences) {
        EXPECT_FALSE(LineFilterInverter(std::make_unique<SequenceLineFilter>(lineSequence.second, sequencer))(lineSequence.first));
    }
}

TEST_F(SequenceLineFilterTest, LineFilterBuilder) {
    std::shared_ptr<FSTLineSequencer> sequencer = std::make_shared<FSTLineSequencer>();
    LineFilterBuilder builder;

    for(const auto& lineSequence : testLinesSequences) {
        std::unique_ptr<ILineFilter> filter = builder.sequenceLineFilter(lineSequence.second, sequencer).makeLineFilter();

        EXPECT_TRUE((*filter)(lineSequence.first));

        builder.reset();
    }

    for(const auto& lineSequence : testLinesSequences) {
        std::unique_ptr<ILineFilter> filter = builder.sequenceLineFilter(lineSequence.second, sequencer).lineFilterInverter().makeLineFilter();

        EXPECT_FALSE((*filter)(lineSequence.first));

        builder.reset();
    }
}

class LineFillFilterTest: public ::testing::Test
{
protected:
    void SetUp() override
    {
        NS::LineGeneratorBuilder generatorBuilder;

        auto generator = generatorBuilder.allPossibleLinesGenerator(3).makeLineGenerator();

        lines = generator->generateLines();
    }

    std::vector<ILineFilter::Line> lines;
};

TEST_F(LineFillFilterTest, AllNonDefinedLine)
{
    std::shared_ptr<LineFillFilter::ReferenceLine> lineToMatch = std::make_shared<LineFillFilter::ReferenceLine>(std::initializer_list<int>({-1, -1, -1}));
    LineFillFilter fillFilter(lineToMatch);

    for(const auto& line: lines)
    {
        EXPECT_TRUE(fillFilter(line));
    }
};

TEST_F(LineFillFilterTest, IgnoreEmpty)
{
    std::shared_ptr<LineFillFilter::ReferenceLine> lineToMatch = std::make_shared<LineFillFilter::ReferenceLine>(std::initializer_list<int>({0, 0, 0}));
    LineFillFilter fillFilter(lineToMatch);

    for(const auto& line: lines)
    {
        EXPECT_TRUE(fillFilter(line));
    }
};

TEST_F(LineFillFilterTest, FillDefinedLine)
{
    std::shared_ptr<LineFillFilter::ReferenceLine> lineToMatch1 = std::make_shared<LineFillFilter::ReferenceLine>(std::initializer_list<int>({-1, -1, 1}));
    std::shared_ptr<LineFillFilter::ReferenceLine> lineToMatch2 = std::make_shared<LineFillFilter::ReferenceLine>(std::initializer_list<int>({-1, 1, -1}));
    std::shared_ptr<LineFillFilter::ReferenceLine> lineToMatch3 = std::make_shared<LineFillFilter::ReferenceLine>(std::initializer_list<int>({-1, 1, 1}));
    std::shared_ptr<LineFillFilter::ReferenceLine> lineToMatch4 = std::make_shared<LineFillFilter::ReferenceLine>(std::initializer_list<int>({1, -1, -1}));
    std::shared_ptr<LineFillFilter::ReferenceLine> lineToMatch5 = std::make_shared<LineFillFilter::ReferenceLine>(std::initializer_list<int>({1, -1, 1}));
    std::shared_ptr<LineFillFilter::ReferenceLine> lineToMatch6 = std::make_shared<LineFillFilter::ReferenceLine>(std::initializer_list<int>({1, 1, -1}));
    std::shared_ptr<LineFillFilter::ReferenceLine> lineToMatch7 = std::make_shared<LineFillFilter::ReferenceLine>(std::initializer_list<int>({1, 1, 1}));
    
    LineFillFilter fillFilter1(lineToMatch1);
    LineFillFilter fillFilter2(lineToMatch2);
    LineFillFilter fillFilter3(lineToMatch3);
    LineFillFilter fillFilter4(lineToMatch4);
    LineFillFilter fillFilter5(lineToMatch5);
    LineFillFilter fillFilter6(lineToMatch6);
    LineFillFilter fillFilter7(lineToMatch7);

    // Test against filter 1
    EXPECT_FALSE(fillFilter1(lines[0]));
    EXPECT_TRUE(fillFilter1(lines[1]));
    EXPECT_FALSE(fillFilter1(lines[2]));
    EXPECT_TRUE(fillFilter1(lines[3]));
    EXPECT_FALSE(fillFilter1(lines[4]));
    EXPECT_TRUE(fillFilter1(lines[5]));
    EXPECT_FALSE(fillFilter1(lines[6]));
    EXPECT_TRUE(fillFilter1(lines[7]));

    // Test against filter 2
    EXPECT_FALSE(fillFilter2(lines[0]));
    EXPECT_FALSE(fillFilter2(lines[1]));
    EXPECT_TRUE(fillFilter2(lines[2]));
    EXPECT_TRUE(fillFilter2(lines[3]));
    EXPECT_FALSE(fillFilter2(lines[4]));
    EXPECT_FALSE(fillFilter2(lines[5]));
    EXPECT_TRUE(fillFilter2(lines[6]));
    EXPECT_TRUE(fillFilter2(lines[7]));

    // Test against filter 3
    EXPECT_FALSE(fillFilter3(lines[0]));
    EXPECT_FALSE(fillFilter3(lines[1]));
    EXPECT_FALSE(fillFilter3(lines[2]));
    EXPECT_TRUE(fillFilter3(lines[3]));
    EXPECT_FALSE(fillFilter3(lines[4]));
    EXPECT_FALSE(fillFilter3(lines[5]));
    EXPECT_FALSE(fillFilter3(lines[6]));
    EXPECT_TRUE(fillFilter3(lines[7]));

    // Test against filter 4
    EXPECT_FALSE(fillFilter4(lines[0]));
    EXPECT_FALSE(fillFilter4(lines[1]));
    EXPECT_FALSE(fillFilter4(lines[2]));
    EXPECT_FALSE(fillFilter4(lines[3]));
    EXPECT_TRUE(fillFilter4(lines[4]));
    EXPECT_TRUE(fillFilter4(lines[5]));
    EXPECT_TRUE(fillFilter4(lines[6]));
    EXPECT_TRUE(fillFilter4(lines[7]));

    // Test against filter 5
    EXPECT_FALSE(fillFilter5(lines[0]));
    EXPECT_FALSE(fillFilter5(lines[1]));
    EXPECT_FALSE(fillFilter5(lines[2]));
    EXPECT_FALSE(fillFilter5(lines[3]));
    EXPECT_FALSE(fillFilter5(lines[4]));
    EXPECT_TRUE(fillFilter5(lines[5]));
    EXPECT_FALSE(fillFilter5(lines[6]));
    EXPECT_TRUE(fillFilter5(lines[7]));

    // Test against filter 6
    EXPECT_FALSE(fillFilter6(lines[0]));
    EXPECT_FALSE(fillFilter6(lines[1]));
    EXPECT_FALSE(fillFilter6(lines[2]));
    EXPECT_FALSE(fillFilter6(lines[3]));
    EXPECT_FALSE(fillFilter6(lines[4]));
    EXPECT_FALSE(fillFilter6(lines[5]));
    EXPECT_TRUE(fillFilter6(lines[6]));
    EXPECT_TRUE(fillFilter6(lines[7]));

    // Test against filter 7
    EXPECT_FALSE(fillFilter7(lines[0]));
    EXPECT_FALSE(fillFilter7(lines[1]));
    EXPECT_FALSE(fillFilter7(lines[2]));
    EXPECT_FALSE(fillFilter7(lines[3]));
    EXPECT_FALSE(fillFilter7(lines[4]));
    EXPECT_FALSE(fillFilter7(lines[5]));
    EXPECT_FALSE(fillFilter7(lines[6]));
    EXPECT_TRUE(fillFilter7(lines[7]));
}

class LineEmptyFilterTest: public ::testing::Test
{
protected:
    void SetUp() override
    {
        NS::LineGeneratorBuilder generatorBuilder;

        auto generator = generatorBuilder.allPossibleLinesGenerator(3).makeLineGenerator();

        lines = generator->generateLines();
    }

    std::vector<ILineFilter::Line> lines;
};

TEST_F(LineEmptyFilterTest, AllNonDefinedLine)
{
    std::shared_ptr<LineEmptyFilter::ReferenceLine> lineToMatch = std::make_shared<LineFillFilter::ReferenceLine>(std::initializer_list<int>({-1, -1, -1}));
    LineEmptyFilter emptyFilter(lineToMatch);

    for(const auto& line: lines)
    {
        EXPECT_TRUE(emptyFilter(line));
    }
};

TEST_F(LineEmptyFilterTest, IgnoreFilled)
{
    std::shared_ptr<LineEmptyFilter::ReferenceLine> lineToMatch = std::make_shared<LineFillFilter::ReferenceLine>(std::initializer_list<int>({1, 1, 1}));
    LineEmptyFilter emptyFilter(lineToMatch);

    for(const auto& line: lines)
    {
        EXPECT_TRUE(emptyFilter(line));
    }
};

TEST_F(LineEmptyFilterTest, EmptyDefinedLine)
{
    std::shared_ptr<LineEmptyFilter::ReferenceLine> lineToMatch1 = std::make_shared<LineFillFilter::ReferenceLine>(std::initializer_list<int>({-1, -1, 0}));
    std::shared_ptr<LineEmptyFilter::ReferenceLine> lineToMatch2 = std::make_shared<LineFillFilter::ReferenceLine>(std::initializer_list<int>({-1, 0, -1}));
    std::shared_ptr<LineEmptyFilter::ReferenceLine> lineToMatch3 = std::make_shared<LineFillFilter::ReferenceLine>(std::initializer_list<int>({-1, 0, 0}));
    std::shared_ptr<LineEmptyFilter::ReferenceLine> lineToMatch4 = std::make_shared<LineFillFilter::ReferenceLine>(std::initializer_list<int>({0, -1, -1}));
    std::shared_ptr<LineEmptyFilter::ReferenceLine> lineToMatch5 = std::make_shared<LineFillFilter::ReferenceLine>(std::initializer_list<int>({0, -1, 0}));
    std::shared_ptr<LineEmptyFilter::ReferenceLine> lineToMatch6 = std::make_shared<LineFillFilter::ReferenceLine>(std::initializer_list<int>({0, 0, -1}));
    std::shared_ptr<LineEmptyFilter::ReferenceLine> lineToMatch7 = std::make_shared<LineFillFilter::ReferenceLine>(std::initializer_list<int>({0, 0, 0}));
    
    LineEmptyFilter emptyFilter1(lineToMatch1);
    LineEmptyFilter emptyFilter2(lineToMatch2);
    LineEmptyFilter emptyFilter3(lineToMatch3);
    LineEmptyFilter emptyFilter4(lineToMatch4);
    LineEmptyFilter emptyFilter5(lineToMatch5);
    LineEmptyFilter emptyFilter6(lineToMatch6);
    LineEmptyFilter emptyFilter7(lineToMatch7);

    // Test against filter 1
    EXPECT_TRUE(emptyFilter1(lines[0]));
    EXPECT_FALSE(emptyFilter1(lines[1]));
    EXPECT_TRUE(emptyFilter1(lines[2]));
    EXPECT_FALSE(emptyFilter1(lines[3]));
    EXPECT_TRUE(emptyFilter1(lines[4]));
    EXPECT_FALSE(emptyFilter1(lines[5]));
    EXPECT_TRUE(emptyFilter1(lines[6]));
    EXPECT_FALSE(emptyFilter1(lines[7]));

    // Test against filter 2
    EXPECT_TRUE(emptyFilter2(lines[0]));
    EXPECT_TRUE(emptyFilter2(lines[1]));
    EXPECT_FALSE(emptyFilter2(lines[2]));
    EXPECT_FALSE(emptyFilter2(lines[3]));
    EXPECT_TRUE(emptyFilter2(lines[4]));
    EXPECT_TRUE(emptyFilter2(lines[5]));
    EXPECT_FALSE(emptyFilter2(lines[6]));
    EXPECT_FALSE(emptyFilter2(lines[7]));

    // Test against filter 3
    EXPECT_TRUE(emptyFilter3(lines[0]));
    EXPECT_FALSE(emptyFilter3(lines[1]));
    EXPECT_FALSE(emptyFilter3(lines[2]));
    EXPECT_FALSE(emptyFilter3(lines[3]));
    EXPECT_TRUE(emptyFilter3(lines[4]));
    EXPECT_FALSE(emptyFilter3(lines[5]));
    EXPECT_FALSE(emptyFilter3(lines[6]));
    EXPECT_FALSE(emptyFilter3(lines[7]));

    // Test against filter 4
    EXPECT_TRUE(emptyFilter4(lines[0]));
    EXPECT_TRUE(emptyFilter4(lines[1]));
    EXPECT_TRUE(emptyFilter4(lines[2]));
    EXPECT_TRUE(emptyFilter4(lines[3]));
    EXPECT_FALSE(emptyFilter4(lines[4]));
    EXPECT_FALSE(emptyFilter4(lines[5]));
    EXPECT_FALSE(emptyFilter4(lines[6]));
    EXPECT_FALSE(emptyFilter4(lines[7]));

    // Test against filter 5
    EXPECT_TRUE(emptyFilter5(lines[0]));
    EXPECT_FALSE(emptyFilter5(lines[1]));
    EXPECT_TRUE(emptyFilter5(lines[2]));
    EXPECT_FALSE(emptyFilter5(lines[3]));
    EXPECT_FALSE(emptyFilter5(lines[4]));
    EXPECT_FALSE(emptyFilter5(lines[5]));
    EXPECT_FALSE(emptyFilter5(lines[6]));
    EXPECT_FALSE(emptyFilter5(lines[7]));

    // Test against filter 6
    EXPECT_TRUE(emptyFilter6(lines[0]));
    EXPECT_TRUE(emptyFilter6(lines[1]));
    EXPECT_FALSE(emptyFilter6(lines[2]));
    EXPECT_FALSE(emptyFilter6(lines[3]));
    EXPECT_FALSE(emptyFilter6(lines[4]));
    EXPECT_FALSE(emptyFilter6(lines[5]));
    EXPECT_FALSE(emptyFilter6(lines[6]));
    EXPECT_FALSE(emptyFilter6(lines[7]));

    // Test against filter 7
    EXPECT_TRUE(emptyFilter7(lines[0]));
    EXPECT_FALSE(emptyFilter7(lines[1]));
    EXPECT_FALSE(emptyFilter7(lines[2]));
    EXPECT_FALSE(emptyFilter7(lines[3]));
    EXPECT_FALSE(emptyFilter7(lines[4]));
    EXPECT_FALSE(emptyFilter7(lines[5]));
    EXPECT_FALSE(emptyFilter7(lines[6]));
    EXPECT_FALSE(emptyFilter7(lines[7]));
}

class LineMatchFilterTest: public ::testing::Test
{
protected:
    void SetUp() override
    {
        NS::LineGeneratorBuilder generatorBuilder;

        auto generator = generatorBuilder.allPossibleLinesGenerator(3).makeLineGenerator();

        lines = generator->generateLines();
    }

    std::vector<ILineFilter::Line> lines;
};

TEST_F(LineMatchFilterTest, AllNonDefinedLine)
{
    std::shared_ptr<LineMatchFilter::ReferenceLine> lineToMatch = std::make_shared<LineFillFilter::ReferenceLine>(std::initializer_list<int>({-1, -1, -1}));
    LineMatchFilter matchFilter(lineToMatch);

    for(const auto& line: lines)
    {
        EXPECT_TRUE(matchFilter(line));
    }
};

TEST_F(LineMatchFilterTest, FillDefinedLine)
{
    std::shared_ptr<LineFillFilter::ReferenceLine> lineToMatch1 = std::make_shared<LineFillFilter::ReferenceLine>(std::initializer_list<int>({-1, -1, 1}));
    std::shared_ptr<LineFillFilter::ReferenceLine> lineToMatch2 = std::make_shared<LineFillFilter::ReferenceLine>(std::initializer_list<int>({-1, 1, -1}));
    std::shared_ptr<LineFillFilter::ReferenceLine> lineToMatch3 = std::make_shared<LineFillFilter::ReferenceLine>(std::initializer_list<int>({-1, 1, 1}));
    std::shared_ptr<LineFillFilter::ReferenceLine> lineToMatch4 = std::make_shared<LineFillFilter::ReferenceLine>(std::initializer_list<int>({1, -1, -1}));
    std::shared_ptr<LineFillFilter::ReferenceLine> lineToMatch5 = std::make_shared<LineFillFilter::ReferenceLine>(std::initializer_list<int>({1, -1, 1}));
    std::shared_ptr<LineFillFilter::ReferenceLine> lineToMatch6 = std::make_shared<LineFillFilter::ReferenceLine>(std::initializer_list<int>({1, 1, -1}));
    std::shared_ptr<LineFillFilter::ReferenceLine> lineToMatch7 = std::make_shared<LineFillFilter::ReferenceLine>(std::initializer_list<int>({1, 1, 1}));
    
    LineFillFilter matchFilter1(lineToMatch1);
    LineFillFilter matchFilter2(lineToMatch2);
    LineFillFilter matchFilter3(lineToMatch3);
    LineFillFilter matchFilter4(lineToMatch4);
    LineFillFilter matchFilter5(lineToMatch5);
    LineFillFilter matchFilter6(lineToMatch6);
    LineFillFilter matchFilter7(lineToMatch7);

    // Test against filter 1
    EXPECT_FALSE(matchFilter1(lines[0]));
    EXPECT_TRUE(matchFilter1(lines[1]));
    EXPECT_FALSE(matchFilter1(lines[2]));
    EXPECT_TRUE(matchFilter1(lines[3]));
    EXPECT_FALSE(matchFilter1(lines[4]));
    EXPECT_TRUE(matchFilter1(lines[5]));
    EXPECT_FALSE(matchFilter1(lines[6]));
    EXPECT_TRUE(matchFilter1(lines[7]));

    // Test against filter 2
    EXPECT_FALSE(matchFilter2(lines[0]));
    EXPECT_FALSE(matchFilter2(lines[1]));
    EXPECT_TRUE(matchFilter2(lines[2]));
    EXPECT_TRUE(matchFilter2(lines[3]));
    EXPECT_FALSE(matchFilter2(lines[4]));
    EXPECT_FALSE(matchFilter2(lines[5]));
    EXPECT_TRUE(matchFilter2(lines[6]));
    EXPECT_TRUE(matchFilter2(lines[7]));

    // Test against filter 3
    EXPECT_FALSE(matchFilter3(lines[0]));
    EXPECT_FALSE(matchFilter3(lines[1]));
    EXPECT_FALSE(matchFilter3(lines[2]));
    EXPECT_TRUE(matchFilter3(lines[3]));
    EXPECT_FALSE(matchFilter3(lines[4]));
    EXPECT_FALSE(matchFilter3(lines[5]));
    EXPECT_FALSE(matchFilter3(lines[6]));
    EXPECT_TRUE(matchFilter3(lines[7]));

    // Test against filter 4
    EXPECT_FALSE(matchFilter4(lines[0]));
    EXPECT_FALSE(matchFilter4(lines[1]));
    EXPECT_FALSE(matchFilter4(lines[2]));
    EXPECT_FALSE(matchFilter4(lines[3]));
    EXPECT_TRUE(matchFilter4(lines[4]));
    EXPECT_TRUE(matchFilter4(lines[5]));
    EXPECT_TRUE(matchFilter4(lines[6]));
    EXPECT_TRUE(matchFilter4(lines[7]));

    // Test against filter 5
    EXPECT_FALSE(matchFilter5(lines[0]));
    EXPECT_FALSE(matchFilter5(lines[1]));
    EXPECT_FALSE(matchFilter5(lines[2]));
    EXPECT_FALSE(matchFilter5(lines[3]));
    EXPECT_FALSE(matchFilter5(lines[4]));
    EXPECT_TRUE(matchFilter5(lines[5]));
    EXPECT_FALSE(matchFilter5(lines[6]));
    EXPECT_TRUE(matchFilter5(lines[7]));

    // Test against filter 6
    EXPECT_FALSE(matchFilter6(lines[0]));
    EXPECT_FALSE(matchFilter6(lines[1]));
    EXPECT_FALSE(matchFilter6(lines[2]));
    EXPECT_FALSE(matchFilter6(lines[3]));
    EXPECT_FALSE(matchFilter6(lines[4]));
    EXPECT_FALSE(matchFilter6(lines[5]));
    EXPECT_TRUE(matchFilter6(lines[6]));
    EXPECT_TRUE(matchFilter6(lines[7]));

    // Test against filter 7
    EXPECT_FALSE(matchFilter7(lines[0]));
    EXPECT_FALSE(matchFilter7(lines[1]));
    EXPECT_FALSE(matchFilter7(lines[2]));
    EXPECT_FALSE(matchFilter7(lines[3]));
    EXPECT_FALSE(matchFilter7(lines[4]));
    EXPECT_FALSE(matchFilter7(lines[5]));
    EXPECT_FALSE(matchFilter7(lines[6]));
    EXPECT_TRUE(matchFilter7(lines[7]));
}

TEST_F(LineMatchFilterTest, EmptyDefinedLine)
{
    std::shared_ptr<LineMatchFilter::ReferenceLine> lineToMatch1 = std::make_shared<LineFillFilter::ReferenceLine>(std::initializer_list<int>({-1, -1, 0}));
    std::shared_ptr<LineMatchFilter::ReferenceLine> lineToMatch2 = std::make_shared<LineFillFilter::ReferenceLine>(std::initializer_list<int>({-1, 0, -1}));
    std::shared_ptr<LineMatchFilter::ReferenceLine> lineToMatch3 = std::make_shared<LineFillFilter::ReferenceLine>(std::initializer_list<int>({-1, 0, 0}));
    std::shared_ptr<LineMatchFilter::ReferenceLine> lineToMatch4 = std::make_shared<LineFillFilter::ReferenceLine>(std::initializer_list<int>({0, -1, -1}));
    std::shared_ptr<LineMatchFilter::ReferenceLine> lineToMatch5 = std::make_shared<LineFillFilter::ReferenceLine>(std::initializer_list<int>({0, -1, 0}));
    std::shared_ptr<LineMatchFilter::ReferenceLine> lineToMatch6 = std::make_shared<LineFillFilter::ReferenceLine>(std::initializer_list<int>({0, 0, -1}));
    std::shared_ptr<LineMatchFilter::ReferenceLine> lineToMatch7 = std::make_shared<LineFillFilter::ReferenceLine>(std::initializer_list<int>({0, 0, 0}));
    
    LineMatchFilter matchFilter1(lineToMatch1);
    LineMatchFilter matchFilter2(lineToMatch2);
    LineMatchFilter matchFilter3(lineToMatch3);
    LineMatchFilter matchFilter4(lineToMatch4);
    LineMatchFilter matchFilter5(lineToMatch5);
    LineMatchFilter matchFilter6(lineToMatch6);
    LineMatchFilter matchFilter7(lineToMatch7);

    // Test against filter 1
    EXPECT_TRUE(matchFilter1(lines[0]));
    EXPECT_FALSE(matchFilter1(lines[1]));
    EXPECT_TRUE(matchFilter1(lines[2]));
    EXPECT_FALSE(matchFilter1(lines[3]));
    EXPECT_TRUE(matchFilter1(lines[4]));
    EXPECT_FALSE(matchFilter1(lines[5]));
    EXPECT_TRUE(matchFilter1(lines[6]));
    EXPECT_FALSE(matchFilter1(lines[7]));

    // Test against filter 2
    EXPECT_TRUE(matchFilter2(lines[0]));
    EXPECT_TRUE(matchFilter2(lines[1]));
    EXPECT_FALSE(matchFilter2(lines[2]));
    EXPECT_FALSE(matchFilter2(lines[3]));
    EXPECT_TRUE(matchFilter2(lines[4]));
    EXPECT_TRUE(matchFilter2(lines[5]));
    EXPECT_FALSE(matchFilter2(lines[6]));
    EXPECT_FALSE(matchFilter2(lines[7]));

    // Test against filter 3
    EXPECT_TRUE(matchFilter3(lines[0]));
    EXPECT_FALSE(matchFilter3(lines[1]));
    EXPECT_FALSE(matchFilter3(lines[2]));
    EXPECT_FALSE(matchFilter3(lines[3]));
    EXPECT_TRUE(matchFilter3(lines[4]));
    EXPECT_FALSE(matchFilter3(lines[5]));
    EXPECT_FALSE(matchFilter3(lines[6]));
    EXPECT_FALSE(matchFilter3(lines[7]));

    // Test against filter 4
    EXPECT_TRUE(matchFilter4(lines[0]));
    EXPECT_TRUE(matchFilter4(lines[1]));
    EXPECT_TRUE(matchFilter4(lines[2]));
    EXPECT_TRUE(matchFilter4(lines[3]));
    EXPECT_FALSE(matchFilter4(lines[4]));
    EXPECT_FALSE(matchFilter4(lines[5]));
    EXPECT_FALSE(matchFilter4(lines[6]));
    EXPECT_FALSE(matchFilter4(lines[7]));

    // Test against filter 5
    EXPECT_TRUE(matchFilter5(lines[0]));
    EXPECT_FALSE(matchFilter5(lines[1]));
    EXPECT_TRUE(matchFilter5(lines[2]));
    EXPECT_FALSE(matchFilter5(lines[3]));
    EXPECT_FALSE(matchFilter5(lines[4]));
    EXPECT_FALSE(matchFilter5(lines[5]));
    EXPECT_FALSE(matchFilter5(lines[6]));
    EXPECT_FALSE(matchFilter5(lines[7]));

    // Test against filter 6
    EXPECT_TRUE(matchFilter6(lines[0]));
    EXPECT_TRUE(matchFilter6(lines[1]));
    EXPECT_FALSE(matchFilter6(lines[2]));
    EXPECT_FALSE(matchFilter6(lines[3]));
    EXPECT_FALSE(matchFilter6(lines[4]));
    EXPECT_FALSE(matchFilter6(lines[5]));
    EXPECT_FALSE(matchFilter6(lines[6]));
    EXPECT_FALSE(matchFilter6(lines[7]));

    // Test against filter 7
    EXPECT_TRUE(matchFilter7(lines[0]));
    EXPECT_FALSE(matchFilter7(lines[1]));
    EXPECT_FALSE(matchFilter7(lines[2]));
    EXPECT_FALSE(matchFilter7(lines[3]));
    EXPECT_FALSE(matchFilter7(lines[4]));
    EXPECT_FALSE(matchFilter7(lines[5]));
    EXPECT_FALSE(matchFilter7(lines[6]));
    EXPECT_FALSE(matchFilter7(lines[7]));
}

TEST_F(LineMatchFilterTest, FullyDefinedLine)
{
    std::shared_ptr<LineMatchFilter::ReferenceLine> lineToMatch1 = std::make_shared<LineFillFilter::ReferenceLine>(std::initializer_list<int>({0, 0, 1}));
    std::shared_ptr<LineMatchFilter::ReferenceLine> lineToMatch2 = std::make_shared<LineFillFilter::ReferenceLine>(std::initializer_list<int>({0, 1, 0}));
    std::shared_ptr<LineMatchFilter::ReferenceLine> lineToMatch3 = std::make_shared<LineFillFilter::ReferenceLine>(std::initializer_list<int>({0, 1, 1}));
    std::shared_ptr<LineMatchFilter::ReferenceLine> lineToMatch4 = std::make_shared<LineFillFilter::ReferenceLine>(std::initializer_list<int>({1, 0, 0}));
    std::shared_ptr<LineMatchFilter::ReferenceLine> lineToMatch5 = std::make_shared<LineFillFilter::ReferenceLine>(std::initializer_list<int>({1, 0, 1}));
    std::shared_ptr<LineMatchFilter::ReferenceLine> lineToMatch6 = std::make_shared<LineFillFilter::ReferenceLine>(std::initializer_list<int>({1, 1, 0}));
    std::shared_ptr<LineMatchFilter::ReferenceLine> lineToMatch7 = std::make_shared<LineFillFilter::ReferenceLine>(std::initializer_list<int>({1, 1, 1}));
    
    LineMatchFilter matchFilter1(lineToMatch1);
    LineMatchFilter matchFilter2(lineToMatch2);
    LineMatchFilter matchFilter3(lineToMatch3);
    LineMatchFilter matchFilter4(lineToMatch4);
    LineMatchFilter matchFilter5(lineToMatch5);
    LineMatchFilter matchFilter6(lineToMatch6);
    LineMatchFilter matchFilter7(lineToMatch7);

    // Test against filter 1
    EXPECT_FALSE(matchFilter1(lines[0]));
    EXPECT_TRUE(matchFilter1(lines[1]));
    EXPECT_FALSE(matchFilter1(lines[2]));
    EXPECT_FALSE(matchFilter1(lines[3]));
    EXPECT_FALSE(matchFilter1(lines[4]));
    EXPECT_FALSE(matchFilter1(lines[5]));
    EXPECT_FALSE(matchFilter1(lines[6]));
    EXPECT_FALSE(matchFilter1(lines[7]));

    // Test against filter 2
    EXPECT_FALSE(matchFilter2(lines[0]));
    EXPECT_FALSE(matchFilter2(lines[1]));
    EXPECT_TRUE(matchFilter2(lines[2]));
    EXPECT_FALSE(matchFilter2(lines[3]));
    EXPECT_FALSE(matchFilter2(lines[4]));
    EXPECT_FALSE(matchFilter2(lines[5]));
    EXPECT_FALSE(matchFilter2(lines[6]));
    EXPECT_FALSE(matchFilter2(lines[7]));

    // Test against filter 3
    EXPECT_FALSE(matchFilter3(lines[0]));
    EXPECT_FALSE(matchFilter3(lines[1]));
    EXPECT_FALSE(matchFilter3(lines[2]));
    EXPECT_TRUE(matchFilter3(lines[3]));
    EXPECT_FALSE(matchFilter3(lines[4]));
    EXPECT_FALSE(matchFilter3(lines[5]));
    EXPECT_FALSE(matchFilter3(lines[6]));
    EXPECT_FALSE(matchFilter3(lines[7]));

    // Test against filter 4
    EXPECT_FALSE(matchFilter4(lines[0]));
    EXPECT_FALSE(matchFilter4(lines[1]));
    EXPECT_FALSE(matchFilter4(lines[2]));
    EXPECT_FALSE(matchFilter4(lines[3]));
    EXPECT_TRUE(matchFilter4(lines[4]));
    EXPECT_FALSE(matchFilter4(lines[5]));
    EXPECT_FALSE(matchFilter4(lines[6]));
    EXPECT_FALSE(matchFilter4(lines[7]));

    // Test against filter 5
    EXPECT_FALSE(matchFilter5(lines[0]));
    EXPECT_FALSE(matchFilter5(lines[1]));
    EXPECT_FALSE(matchFilter5(lines[2]));
    EXPECT_FALSE(matchFilter5(lines[3]));
    EXPECT_FALSE(matchFilter5(lines[4]));
    EXPECT_TRUE(matchFilter5(lines[5]));
    EXPECT_FALSE(matchFilter5(lines[6]));
    EXPECT_FALSE(matchFilter5(lines[7]));

    // Test against filter 6
    EXPECT_FALSE(matchFilter6(lines[0]));
    EXPECT_FALSE(matchFilter6(lines[1]));
    EXPECT_FALSE(matchFilter6(lines[2]));
    EXPECT_FALSE(matchFilter6(lines[3]));
    EXPECT_FALSE(matchFilter6(lines[4]));
    EXPECT_FALSE(matchFilter6(lines[5]));
    EXPECT_TRUE(matchFilter6(lines[6]));
    EXPECT_FALSE(matchFilter6(lines[7]));

    // Test against filter 7
    EXPECT_FALSE(matchFilter7(lines[0]));
    EXPECT_FALSE(matchFilter7(lines[1]));
    EXPECT_FALSE(matchFilter7(lines[2]));
    EXPECT_FALSE(matchFilter7(lines[3]));
    EXPECT_FALSE(matchFilter7(lines[4]));
    EXPECT_FALSE(matchFilter7(lines[5]));
    EXPECT_FALSE(matchFilter7(lines[6]));
    EXPECT_TRUE(matchFilter7(lines[7]));
}