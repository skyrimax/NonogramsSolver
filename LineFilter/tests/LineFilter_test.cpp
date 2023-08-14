#include <gtest/gtest.h>

#include <SequenceLineFilter.hpp>
#include <FSTLineSequencer.hpp>
#include <LineEmptyFilter.hpp>
#include <LineFillFilter.hpp>
#include <LineFilterInverter.hpp>
#include <LineFilterBuilder.hpp>

#include <LineGeneratorBuilder.hpp>

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
                std::pair<ILineSequencer::Line, ILineSequencer::Sequence>(
                    {0, 1, 0, 1, 0},
                    {1, 1}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, ILineSequencer::Sequence>(
                    {1, 1, 1, 1, 1},
                    {5}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, ILineSequencer::Sequence>(
                    {1, 1, 1, 1, 1},
                    {5}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, ILineSequencer::Sequence>(
                    {0, 1, 1, 1, 0},
                    {3}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, ILineSequencer::Sequence>(
                    {0, 0, 1, 0, 0},
                    {1}
                )
            );
        // Columns
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, ILineSequencer::Sequence>(
                    {0, 1, 1, 0, 0},
                    {2}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, ILineSequencer::Sequence>(
                    {1, 1, 1, 1, 0},
                    {4}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, ILineSequencer::Sequence>(
                    {0, 1, 1, 1, 1},
                    {4}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, ILineSequencer::Sequence>(
                    {1, 1, 1, 1, 0},
                    {4}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, ILineSequencer::Sequence>(
                    {0, 1, 1, 0, 0},
                    {2}
                )
            );

        // lvl # 1-2 (10x10)
        // Rows
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, ILineSequencer::Sequence>(
                    {1, 1, 0, 0, 1, 0, 0, 1, 1, 1},
                    {2, 1, 3}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, ILineSequencer::Sequence>(
                    {1, 0, 0, 0, 0, 0, 1, 0, 1, 1},
                    {1, 1, 2}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, ILineSequencer::Sequence>(
                    {1, 0, 0, 0, 0, 0, 1, 0, 1, 1},
                    {1, 1, 2}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, ILineSequencer::Sequence>(
                    {1, 0, 0, 0, 0, 0, 0, 0, 1, 1},
                    {1, 2}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, ILineSequencer::Sequence>(
                    {1, 1, 0, 0, 0, 0, 0, 1, 1, 1},
                    {2, 3}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, ILineSequencer::Sequence>(
                    {1, 1, 1, 0, 0, 0, 1, 1, 1, 1},
                    {3, 4}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, ILineSequencer::Sequence>(
                    {1, 1, 1, 1, 0, 1, 1, 1, 0, 1},
                    {4, 3, 1}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, ILineSequencer::Sequence>(
                    {1, 0, 1, 1, 1, 1, 1, 0, 1, 0},
                    {1, 5, 1}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, ILineSequencer::Sequence>(
                    {0, 1, 0, 1, 1, 0, 1, 1, 0, 1},
                    {1, 2, 2, 1}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, ILineSequencer::Sequence>(
                    {1, 0, 1, 1, 0, 1, 0, 1, 1, 1},
                    {1, 2, 1, 3}
                )
            );
        // Columns
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, ILineSequencer::Sequence>(
                    {1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
                    {8, 1}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, ILineSequencer::Sequence>(
                    {1, 0, 0, 0, 1, 1, 1, 0, 1, 0},
                    {1, 3, 1}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, ILineSequencer::Sequence>(
                    {0, 0, 0, 0, 0, 1, 1, 1, 0, 1},
                    {3, 1}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, ILineSequencer::Sequence>(
                    {0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
                    {4}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, ILineSequencer::Sequence>(
                    {1, 0, 0, 0, 0, 0, 0, 1, 1, 0},
                    {1, 2}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, ILineSequencer::Sequence>(
                    {0, 0, 0, 0, 0, 0, 1, 1, 0, 1},
                    {2, 1}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, ILineSequencer::Sequence>(
                    {0, 1, 1, 0, 0, 1, 1, 1, 1, 0},
                    {2, 4}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, ILineSequencer::Sequence>(
                    {1, 0, 0, 0, 1, 1, 1, 0, 1, 1},
                    {1, 3, 2}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, ILineSequencer::Sequence>(
                    {1, 1, 1, 1, 1, 1, 0, 1, 0, 1},
                    {6, 1, 1}
                )
            );
        testLinesSequences
            .push_back(
                std::pair<ILineSequencer::Line, ILineSequencer::Sequence>(
                    {1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
                    {7, 2}
                )
            );
    }

    std::vector<std::pair<ILineSequencer::Line, ILineSequencer::Sequence>> testLinesSequences;
};

TEST_F(SequenceLineFilterTest, SequenceLineFilter) {
    FSTLineSequencer sequencer;

    for(const auto& lineSequence : testLinesSequences) {
        EXPECT_TRUE(SequenceLineFilter(lineSequence.second, sequencer)(lineSequence.first));
    }
}

TEST_F(SequenceLineFilterTest, LineFilterInverter) {
    FSTLineSequencer sequencer;

    for(const auto& lineSequence : testLinesSequences) {
        EXPECT_FALSE(LineFilterInverter(new SequenceLineFilter(lineSequence.second, sequencer))(lineSequence.first));
    }
}

TEST_F(SequenceLineFilterTest, LineFilterBuilder) {
    FSTLineSequencer sequencer;
    LineFilterBuilder builder;

    for(const auto& lineSequence : testLinesSequences) {
        ILineFilter* filter = builder.sequenceLineFilter(lineSequence.second, sequencer).makeLineFilter();

        EXPECT_TRUE((*filter)(lineSequence.first));

        delete filter;
        builder.reset();
    }

    for(const auto& lineSequence : testLinesSequences) {
        ILineFilter* filter = builder.sequenceLineFilter(lineSequence.second, sequencer).lineFilterInverter().makeLineFilter();

        EXPECT_FALSE((*filter)(lineSequence.first));

        delete filter;
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

        delete generator;
    }

    std::vector<ILineFilter::Line> lines;
};

TEST_F(LineFillFilterTest, AllNonDefinedLine)
{
    LineFillFilter::ReferenceLine lineToMatch({-1, -1, -1});
    LineFillFilter fileFilter(lineToMatch);

    for(const auto& line: lines)
    {
        EXPECT_TRUE(fileFilter(line));
    }
};

TEST_F(LineFillFilterTest, IgnoreEmpty)
{
    LineFillFilter::ReferenceLine lineToMatch({0, 0, 0});
    LineFillFilter fileFilter(lineToMatch);

    for(const auto& line: lines)
    {
        EXPECT_TRUE(fileFilter(line));
    }
};

TEST_F(LineFillFilterTest, FillDefinedLine)
{
    LineFillFilter::ReferenceLine lineToMatch1({-1, -1, 1});
    LineFillFilter::ReferenceLine lineToMatch2({-1, 1, -1});
    LineFillFilter::ReferenceLine lineToMatch3({-1, 1, 1});
    LineFillFilter::ReferenceLine lineToMatch4({1, -1, -1});
    LineFillFilter::ReferenceLine lineToMatch5({1, -1, 1});
    LineFillFilter::ReferenceLine lineToMatch6({1, 1, -1});
    LineFillFilter::ReferenceLine lineToMatch7({1, 1, 1});
    
    LineFillFilter filFilter1(lineToMatch1);
    LineFillFilter filFilter2(lineToMatch2);
    LineFillFilter filFilter3(lineToMatch3);
    LineFillFilter filFilter4(lineToMatch4);
    LineFillFilter filFilter5(lineToMatch5);
    LineFillFilter filFilter6(lineToMatch6);
    LineFillFilter filFilter7(lineToMatch7);

    // Test against filter 1
    EXPECT_FALSE(filFilter1(lines[0]));
    EXPECT_TRUE(filFilter1(lines[1]));
    EXPECT_FALSE(filFilter1(lines[2]));
    EXPECT_TRUE(filFilter1(lines[3]));
    EXPECT_FALSE(filFilter1(lines[4]));
    EXPECT_TRUE(filFilter1(lines[5]));
    EXPECT_FALSE(filFilter1(lines[6]));
    EXPECT_TRUE(filFilter1(lines[7]));

    // Test against filter 2
    EXPECT_FALSE(filFilter2(lines[0]));
    EXPECT_FALSE(filFilter2(lines[1]));
    EXPECT_TRUE(filFilter2(lines[2]));
    EXPECT_TRUE(filFilter2(lines[3]));
    EXPECT_FALSE(filFilter2(lines[4]));
    EXPECT_FALSE(filFilter2(lines[5]));
    EXPECT_TRUE(filFilter2(lines[6]));
    EXPECT_TRUE(filFilter2(lines[7]));

    // Test against filter 3
    EXPECT_FALSE(filFilter3(lines[0]));
    EXPECT_FALSE(filFilter3(lines[1]));
    EXPECT_FALSE(filFilter3(lines[2]));
    EXPECT_TRUE(filFilter3(lines[3]));
    EXPECT_FALSE(filFilter3(lines[4]));
    EXPECT_FALSE(filFilter3(lines[5]));
    EXPECT_FALSE(filFilter3(lines[6]));
    EXPECT_TRUE(filFilter3(lines[7]));

    // Test against filter 4
    EXPECT_FALSE(filFilter4(lines[0]));
    EXPECT_FALSE(filFilter4(lines[1]));
    EXPECT_FALSE(filFilter4(lines[2]));
    EXPECT_FALSE(filFilter4(lines[3]));
    EXPECT_TRUE(filFilter4(lines[4]));
    EXPECT_TRUE(filFilter4(lines[5]));
    EXPECT_TRUE(filFilter4(lines[6]));
    EXPECT_TRUE(filFilter4(lines[7]));

    // Test against filter 5
    EXPECT_FALSE(filFilter5(lines[0]));
    EXPECT_FALSE(filFilter5(lines[1]));
    EXPECT_FALSE(filFilter5(lines[2]));
    EXPECT_FALSE(filFilter5(lines[3]));
    EXPECT_FALSE(filFilter5(lines[4]));
    EXPECT_TRUE(filFilter5(lines[5]));
    EXPECT_FALSE(filFilter5(lines[6]));
    EXPECT_TRUE(filFilter5(lines[7]));

    // Test against filter 6
    EXPECT_FALSE(filFilter6(lines[0]));
    EXPECT_FALSE(filFilter6(lines[1]));
    EXPECT_FALSE(filFilter6(lines[2]));
    EXPECT_FALSE(filFilter6(lines[3]));
    EXPECT_FALSE(filFilter6(lines[4]));
    EXPECT_FALSE(filFilter6(lines[5]));
    EXPECT_TRUE(filFilter6(lines[6]));
    EXPECT_TRUE(filFilter6(lines[7]));

    // Test against filter 7
    EXPECT_FALSE(filFilter7(lines[0]));
    EXPECT_FALSE(filFilter7(lines[1]));
    EXPECT_FALSE(filFilter7(lines[2]));
    EXPECT_FALSE(filFilter7(lines[3]));
    EXPECT_FALSE(filFilter7(lines[4]));
    EXPECT_FALSE(filFilter7(lines[5]));
    EXPECT_FALSE(filFilter7(lines[6]));
    EXPECT_TRUE(filFilter7(lines[7]));
}

class LineEmptyFilterTest: public ::testing::Test
{
protected:
    void SetUp() override
    {
        NS::LineGeneratorBuilder generatorBuilder;

        auto generator = generatorBuilder.allPossibleLinesGenerator(3).makeLineGenerator();

        lines = generator->generateLines();

        delete generator;
    }

    std::vector<ILineFilter::Line> lines;
};

TEST_F(LineEmptyFilterTest, AllNonDefinedLine)
{
    LineEmptyFilter::ReferenceLine lineToMatch({-1, -1, -1});
    LineEmptyFilter fileFilter(lineToMatch);

    for(const auto& line: lines)
    {
        EXPECT_TRUE(fileFilter(line));
    }
};

TEST_F(LineEmptyFilterTest, IgnoreFilled)
{
    LineEmptyFilter::ReferenceLine lineToMatch({1, 1, 1});
    LineEmptyFilter fileFilter(lineToMatch);

    for(const auto& line: lines)
    {
        EXPECT_TRUE(fileFilter(line));
    }
};

TEST_F(LineEmptyFilterTest, FillDefinedLine)
{
    LineEmptyFilter::ReferenceLine lineToMatch1({-1, -1, 0});
    LineEmptyFilter::ReferenceLine lineToMatch2({-1, 0, -1});
    LineEmptyFilter::ReferenceLine lineToMatch3({-1, 0, 0});
    LineEmptyFilter::ReferenceLine lineToMatch4({0, -1, -1});
    LineEmptyFilter::ReferenceLine lineToMatch5({0, -1, 0});
    LineEmptyFilter::ReferenceLine lineToMatch6({0, 0, -1});
    LineEmptyFilter::ReferenceLine lineToMatch7({0, 0, 0});
    
    LineEmptyFilter filFilter1(lineToMatch1);
    LineEmptyFilter filFilter2(lineToMatch2);
    LineEmptyFilter filFilter3(lineToMatch3);
    LineEmptyFilter filFilter4(lineToMatch4);
    LineEmptyFilter filFilter5(lineToMatch5);
    LineEmptyFilter filFilter6(lineToMatch6);
    LineEmptyFilter filFilter7(lineToMatch7);

    // Test against filter 1
    EXPECT_TRUE(filFilter1(lines[0]));
    EXPECT_FALSE(filFilter1(lines[1]));
    EXPECT_TRUE(filFilter1(lines[2]));
    EXPECT_FALSE(filFilter1(lines[3]));
    EXPECT_TRUE(filFilter1(lines[4]));
    EXPECT_FALSE(filFilter1(lines[5]));
    EXPECT_TRUE(filFilter1(lines[6]));
    EXPECT_FALSE(filFilter1(lines[7]));

    // Test against filter 2
    EXPECT_TRUE(filFilter2(lines[0]));
    EXPECT_TRUE(filFilter2(lines[1]));
    EXPECT_FALSE(filFilter2(lines[2]));
    EXPECT_FALSE(filFilter2(lines[3]));
    EXPECT_TRUE(filFilter2(lines[4]));
    EXPECT_TRUE(filFilter2(lines[5]));
    EXPECT_FALSE(filFilter2(lines[6]));
    EXPECT_FALSE(filFilter2(lines[7]));

    // Test against filter 3
    EXPECT_TRUE(filFilter3(lines[0]));
    EXPECT_FALSE(filFilter3(lines[1]));
    EXPECT_FALSE(filFilter3(lines[2]));
    EXPECT_FALSE(filFilter3(lines[3]));
    EXPECT_TRUE(filFilter3(lines[4]));
    EXPECT_FALSE(filFilter3(lines[5]));
    EXPECT_FALSE(filFilter3(lines[6]));
    EXPECT_FALSE(filFilter3(lines[7]));

    // Test against filter 4
    EXPECT_TRUE(filFilter4(lines[0]));
    EXPECT_TRUE(filFilter4(lines[1]));
    EXPECT_TRUE(filFilter4(lines[2]));
    EXPECT_TRUE(filFilter4(lines[3]));
    EXPECT_FALSE(filFilter4(lines[4]));
    EXPECT_FALSE(filFilter4(lines[5]));
    EXPECT_FALSE(filFilter4(lines[6]));
    EXPECT_FALSE(filFilter4(lines[7]));

    // Test against filter 5
    EXPECT_TRUE(filFilter5(lines[0]));
    EXPECT_FALSE(filFilter5(lines[1]));
    EXPECT_TRUE(filFilter5(lines[2]));
    EXPECT_FALSE(filFilter5(lines[3]));
    EXPECT_FALSE(filFilter5(lines[4]));
    EXPECT_FALSE(filFilter5(lines[5]));
    EXPECT_FALSE(filFilter5(lines[6]));
    EXPECT_FALSE(filFilter5(lines[7]));

    // Test against filter 6
    EXPECT_TRUE(filFilter6(lines[0]));
    EXPECT_TRUE(filFilter6(lines[1]));
    EXPECT_FALSE(filFilter6(lines[2]));
    EXPECT_FALSE(filFilter6(lines[3]));
    EXPECT_FALSE(filFilter6(lines[4]));
    EXPECT_FALSE(filFilter6(lines[5]));
    EXPECT_FALSE(filFilter6(lines[6]));
    EXPECT_FALSE(filFilter6(lines[7]));

    // Test against filter 7
    EXPECT_TRUE(filFilter7(lines[0]));
    EXPECT_FALSE(filFilter7(lines[1]));
    EXPECT_FALSE(filFilter7(lines[2]));
    EXPECT_FALSE(filFilter7(lines[3]));
    EXPECT_FALSE(filFilter7(lines[4]));
    EXPECT_FALSE(filFilter7(lines[5]));
    EXPECT_FALSE(filFilter7(lines[6]));
    EXPECT_FALSE(filFilter7(lines[7]));
}